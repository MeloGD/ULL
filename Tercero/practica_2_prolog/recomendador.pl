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
  % Compañia
  write('*** ¿Con quién va a viajar? ***'), nl,
  write('Solo.'), nl,
  write('Pareja.'), nl,
  write('Amigos.'), nl,
  write('Familia.'), nl,
  read(Answer2), nl,
  % Motivo del viaje
  write('*** ¿Motivo del viaje? ***'), nl,
  write('Cultural.'), nl,
  write('Gastranómico.'), nl,
  write('Ocio.'), nl,
  read(Answer3), nl,
  % Alojamiento
  write('*** ¿Alojamiento? ***'), nl,
  write('Camping.'), nl,
  write('Hotel.'), nl,
  write('Apartamento.'), nl,
  read(Answer4), nl,

  % Resultado
  % destination(Dest,Answer1,Answer2,Answer3,Answer4), nl,
  write('Le recomendamos que viaje a:'), nl,
  conclution(Answer1, Answer2, Answer3, Answer4, Dest),
  write(Dest).

% Opción de salida
option(2) :-
	write('Entendido, saludos.').
  

% Destinos / Hechos
destination('Moscú, Rusia.', -15,'solo','cultural','hotel').
destination('El Cairo, Egitpo', 32,'familia','cultural','hotel').

% Conclusiones
%conclution(A, B, C, D, Dest) :- A == 'frio', B == 'solo', C == 'cultural', D == 'hotel', Dest = 'Rusia'.
%conclution(A, B, C, D, Dest) :- A == 'calido', B == 'familia', C == 'cultural', D == 'hotel', Dest = 'Egipto'.


% Buscador / Predicados
conclution(A, B, C, D, Dest) :- weather(A,Dest), people(B, Dest), reason(C, Dest), residence(D, Dest).
%weather(A, Dest) :- destination(Dest,A,_,_,_).
people(B, Dest) :- destination(Dest,_,B,_,_).
reason(C, Dest) :- destination(Dest,_,_,C,_).
residence(D, Dest) :- destination(Dest,_,_,_,D).

% Clima
weather(A, Dest) :- destination(Dest,Temp,_,_,_) , Temp < 15, A == 'frio'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_) , Temp > 15, Temp < 30, A == 'templado'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_) , Temp > 30, A == 'calido'.