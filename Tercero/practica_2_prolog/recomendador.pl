% Comienzo del programa
start :-
  write('*** Bienvenido al recomendador de viajes desde la isla de Tenerife, ¿en qué puedo servirle? ***'), nl, nl,
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
  write('*** ¿Qué clima le apetece? ***'), nl,
  write('Frío.'), nl,
  write('Templado.'),nl,
  write('Cálido.'), nl,
  read(Answer1), nl,
  % Estación
  write('*** ¿Qué estación le llama la atención? ***'), nl,
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
  write('Playa.'), nl,
  write('Montaña'), nl,
  write('Entretenimiento.'), nl,
  read(Answer4), nl,
  % Alojamiento
  write('*** ¿Alojamiento? ***'), nl,
  write('Camping.'), nl,
  write('Hotel.'), nl,
  write('Apartamento.'), nl,
  read(Answer5), nl,
  % Presupuesto
  write('*** ¿Cúanto tiene de presupuesto (por persona)? ***'), nl,
  write('*** Recuerde, escriba la palabra en minúsculas. ***'), nl,
  write('Bajo      (≈150).'), nl,
  write('Medio     (≈600).'), nl,
  write('Alto      (≈1000).'), nl,
  read(Answer6),  nl,

  % Resultado
  conclution(Answer1, Answer2, Answer3, Answer4, Answer5, Answer6, Dest),
  write('Le recomendamos que viaje a:'), nl,
  write(Dest).

% Opción de salida
option(2) :-
	write('Entendido, saludos.').
  

%%% Destinos / Hechos
destination('La Gomera, España.', 21,'otoño','pareja','gastronomico','hotel', 40).
destination('La Gomera, España.', 21,'otoño','pareja','montaña','camping', 80).
destination('La Palma, España.', 22,'primavera','pareja','montaña','apartamento', 80).
destination('La Palma, España.', 22,'primavera','amigos','montaña','apartamento', 80).
destination('Fuerteventura, España.', 25,'verano','pareja','playa','camping', 150).
destination('Segovia, España.', 16,'invierno','pareja','cultural','apartamento', 300).
destination('Madrid, España.', 19,'otoño','amigos','diversion','apartamento', 200).
destination('Cracovia, Polonia.', 12,'otoño','amigos','diversion','apartamento', 400).
destination('Praga, República Checa.', 26,'verano','pareja','cultural','hotel', 500).
destination('Moscú, Rusia.', 1,'otoño','solo','cultural','hotel', 520).
destination('Inssbruck, Austria.', 4,'invierno','solo','cultural','hotel', 600).
destination('París, Francia.', 17,'primavera','pareja','cultural','apartamento', 700).
destination('Oslo, Noruega.', 0,'invierno','pareja','montaña','apartamento', 750).
destination('Oslo, Noruega.', 0,'invierno','pareja','montaña','hotel', 900).
destination('Oslo, Noruega.', 0,'invierno','familia','montaña','apartamento', 900).
destination('El Cairo, Egitpo.', 29,'primavera','familia','cultural','hotel', 1000).
destination('París, Francia.', 8,'invierno','pareja','gastronomico','hotel', 1000).
destination('Gandaki, Nepal.', 2,'invierno','amigos','montaña','camping', 1100).
destination('Sidney, Australia.', 22,'primavera','solo','cultural','apartamento', 1200).
destination('Ibiza, España.', 28.5,'verano','amigos','diversion','apartamento', 1300).
destination('Ibiza, España.', 28.5,'verano','amigos','playa','apartamento', 1300).
destination('Kumamoto, Japón.', 21,'Primavera','amigos','cultural','hotel', 1300).
destination('Hawai, Estados Unidos.', 29.4,'verano','pareja','ocio','hotel', 2100).
destination('Las Vegas, Estados Unidos.', 41,'verano','amigos','entretenimiento','hotel', 2500).
destination('Abu Dhabi, Emiratos Árabes.', 41,'verano','pareja','entretenimiento','hotel', 2500).

%%% Buscador / Predicados
conclution(A, B, C, D, E, F, Dest) :- weather(A,Dest), season(B, Dest), people(C, Dest), reason(D, Dest), residence(E, Dest), budget(F, Dest), !.
conclution(_, _, _, _, _, _, Dest) :- Dest = 'No le puedo recomendar un destino con sus parámetros.'.

% Clima
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_,_) , Temp < 15, A == 'frio'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_,_) , Temp > 15, Temp < 30, A == 'templado'.
weather(A, Dest) :- destination(Dest,Temp,_,_,_,_,_) , Temp > 30, A == 'calido'.

% Estación, nº de gente, motivo y estancia
season(B, Dest) :- destination(Dest,_,B,_,_,_,_).
people(C, Dest) :- destination(Dest,_,_,C,_,_,_).
reason(D, Dest) :- destination(Dest,_,_,_,D,_,_).
residence(E, Dest) :- destination(Dest,_,_,_,_,E,_).

% Presupuesto
budget(F, Dest) :- destination(Dest,_,_,_,_,_,Price) , Price < 150, F == 'bajo'.
budget(F, Dest) :- destination(Dest,_,_,_,_,_,Price) , Price > 150, Price < 700, F == 'medio'.
budget(F, Dest) :- destination(Dest,_,_,_,_,_,Price) , Price > 700, F == 'alto'.