% Comienzo del programa
start :-
  write('*** Bienvenido al recomendador de viajes, ¿en qué puedo servirle? ***'), nl, nl,
  write('*** Escoja una de las opciones POR SU NÚMERO ASOCIADO ***'), nl,
  write('1. Ayudame a escoger un destino.'), nl,
  write('2. No, mejor nada.'), nl,
	read(Option), nl,
	option(Option).

% Opción que procede al cuestionario
option(1) :-
	write('*** Ha escogido asesoramiento. ***'), nl,
  write('*** Escriba las respuestas sin mayúsculas o tildes. ***'), nl,
  % Clima
  write('***¿Qué clima le apetece?***'), nl,
  write('Frío.'), nl,
  write('Templado.'),nl,
  write('Cálido.'), nl,
  read(Answer1), nl,
  % Estación
  write('***¿Qué estación le llama la atención?***'), nl,
  write('Primavera.'), nl,
  write('Verano.'),nl,
  write('Otoño.'), nl,
  write('Invierno.'), nl,
  read(Answer2), nl,
  % Compañia
  write('*** ¿Con quién va a viajar? ***'), nl,
  write('Solo.'), nl,
  write('Pareja.'), nl,
  write('Amigos.'), nl,
  write('Familia.'), nl,
  read(Answer3), nl,
  % Motivo del viaje
  write('*** ¿Motivo del viaje? ***'), nl,
  write('Cultural.'), nl,
  write('Gastranómico.'), nl,
  write('Ocio.'), nl,
  read(Answer4), nl,
  % Alojamiento
  write('*** ¿Alojamiento? ***'), nl,
  write('Camping.'), nl,
  write('Hotel.'), nl,
  write('Apartamento.'), nl,
  read(Answer5), nl,

  % Resultado
  % destination(Dest,Answer1,Answer2,Answer3,Answer4), nl,
  write('Le recomendamos que viaje a:'), nl,
  conclution(Answer1, Answer2, Answer3, Answer4, Answer5, Dest),
  write(Dest).

% Opción de salida
option(2) :-
	write('Entendido, saludos.').
  

%%% Destinos / Hechos
destination('Moscú, Rusia.', 1,'otoño','solo','cultural','hotel').
destination('El Cairo, Egitpo', 29,'primavera','familia','cultural','hotel').
destination('Ibiza, España', 28.5,'verano','amigos','ocio','apartamento').
destination('Fuerteventura, España', 25,'verano','pareja','ocio','hotel').
destination('París, Francia', 8,'invierno','pareja','gastronomico','hotel').
destination('París, Francia', 17,'primavera','pareja','cultural','apartamento').
destination('Sidney, Australia', 22,'primavera','solo','ocio','apartamento').
destination('Cracovia, Polonia', 12,'otoño','amigos','ocio','apartamento').
destination('Praga, República Checa', 26,'verano','pareja','cultural','hotel').



% Conclusiones
%conclution(A, B, C, D, Dest) :- A == 'frio', B == 'solo', C == 'cultural', D == 'hotel', Dest = 'Rusia'.
%conclution(A, B, C, D, Dest) :- A == 'calido', B == 'familia', C == 'cultural', D == 'hotel', Dest = 'Egipto'.


%%% Buscador / Predicados
conclution(A, B, C, D, E, Dest) :- weather(A,Dest), season(B, Dest), people(C, Dest), reason(D, Dest), residence(E, Dest).
%weather(A, Dest) :- destination(Dest,A,_,_,_).
season(B, Dest) :- destination(Dest,_,B,_,_,_).
people(C, Dest) :- destination(Dest,_,_,C,_,_).
reason(D, Dest) :- destination(Dest,_,_,_,D,_).
residence(E, Dest) :- destination(Dest,_,_,_,_,E).

% Clima
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_) , Temp < 15, A == 'frio'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_) , Temp > 15, Temp < 30, A == 'templado'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_) , Temp > 30, A == 'calido'.


