Algoritmo GestionProyectos
	Definir codigo, tema, integrantes, observaciones, clave Como Cadena
	Definir avance, retrasos, cant, op Como Entero
	Definir notaFinal, funcionalidad, defensa, estructura, innovacion, promedio, menor Como Real
	Dimensionar codigos(50)
	Dimensionar temas(50)
	Dimensionar integrantesArr(50)
	Dimensionar observacionesArr(50)
	Dimensionar avances(50)
	Dimensionar retrasosArr(50)
	Dimensionar notas(50)
	cant <- 0
	Repetir
		Escribir '=== MENU ==='
		Escribir '1. Registrar Grupo'
		Escribir '2. Reporte (Ordenado por Nota)'
		Escribir '3. Promedio General'
		Escribir '4. Buscar Grupo'
		Escribir '5. Menor Nota'
		Escribir '6. Salir'
		Leer op
		Según op Hacer
			1:
				Escribir 'Codigo: '
				Leer codigo
				Escribir 'Integrantes: '
				Leer integrantes
				Escribir 'Tema: '
				Leer tema
				Escribir 'Avance (%): '
				Leer avance
				Escribir 'Retrasos: '
				Leer retrasos
				Escribir 'Observaciones: '
				Leer observaciones
				Escribir 'Funcionalidad: '
				Leer funcionalidad
				Escribir 'Defensa: '
				Leer defensa
				Escribir 'Estructura: '
				Leer estructura
				Escribir 'Innovacion: '
				Leer innovacion
				Si funcionalidad+defensa+estructura<=10 Entonces
					notaFinal <- funcionalidad+defensa+estructura+innovacion-(retrasos*0.5)
					Si notaFinal>10 Entonces
						notaFinal <- 10
					FinSi
					Si notaFinal<0 Entonces
						notaFinal <- 0
					FinSi
					codigos[cant] <- codigo
					temas[cant] <- tema
					integrantesArr[cant] <- integrantes
					observacionesArr[cant] <- observaciones
					avances[cant] <- avance
					retrasosArr[cant] <- retrasos
					notas[cant] <- notaFinal
					cant <- cant+1
					Escribir 'Registro exitoso'
				SiNo
					Escribir 'Error: suma mayor a 10'
				FinSi
			2:
				Definir i, j Como Entero
				Definir auxNota Como Real
				Definir auxCod, auxTema Como Cadena
				Definir auxAvance Como Entero
				Para i<-0 Hasta cant-2 Hacer
					Para j<-0 Hasta cant-2-i Hacer
						Si notas[j]<notas[j+1] Entonces
							auxNota <- notas[j]
							notas[j] <- notas[j+1]
							notas[j+1]<-auxNota
							auxCod <- codigos[j]
							codigos[j] <- codigos[j+1]
							codigos[j+1]<-auxCod
							auxTema <- temas[j]
							temas[j] <- temas[j+1]
							temas[j+1]<-auxTema
							auxAvance <- avances[j]
							avances[j] <- avances[j+1]
							avances[j+1]<-auxAvance
						FinSi
					FinPara
				FinPara
				Escribir 'COD   AVANCE   NOTA   TEMA'
				Para i<-0 Hasta cant-1 Hacer
					Escribir codigos[i], ' ', avances[i], '% ', notas[i], ' ', temas[i]
				FinPara
			3:
				Si cant>0 Entonces
					promedio <- PromedioRecursivo(notas,cant)
					Escribir 'Promedio General: ', promedio
				SiNo
					Escribir 'No hay datos'
				FinSi
			4:
				Escribir 'Buscar por codigo o tema: '
				Leer clave
				Para i<-0 Hasta cant-1 Hacer
					Si codigos[i]=clave O temas[i]=clave Entonces
						Escribir 'Encontrado: ', codigos[i], ' ', avances[i], '% ', notas[i], ' ', temas[i]
					FinSi
				FinPara
			5:
				Si cant>0 Entonces
					menor <- notas[0]
					Para i<-1 Hasta cant-1 Hacer
						Si notas[i]<menor Entonces
							menor <- notas[i]
						FinSi
					FinPara
					Escribir 'Menor nota registrada: ', menor
				SiNo
					Escribir 'No hay datos'
				FinSi
		FinSegún
	Hasta Que op=6
FinAlgoritmo

Función promedio <- PromedioRecursivo(notas Por Referencia,n)
	Si n=1 Entonces
		promedio <- notas[0]
	SiNo
		promedio <- (notas[n-1]+(n-1)*PromedioRecursivo(notas,n-1))/n
	FinSi
FinFunción

Función SinTitulo
	
FinFunción

Funcion SinTitulo
	
FinFuncion
