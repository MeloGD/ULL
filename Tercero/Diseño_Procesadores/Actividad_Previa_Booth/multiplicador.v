// multiplicador hace referencia al registro Q y multiplicando al registro M
module multiplicador (input wire [2:0] multiplicador, multiplicando, input wire clk, reset, output wire [5:0] resultado, output Fin);
  // Salida de CD con Q, de la cual cogeremos el q0 para poder pasarlo a la UC y poder controlar que operacion hacer junto con qsub1, que viene del FlipFlop
  wire [2:0] salida_q; 
  wire [3:0] salida_a;
  wire CargaA, CargaM, CargaQ, desplaza,  resta, qsub1;

  // module camino_datos (input wire [2:0] entrada_q, entrada_m, input wire CargaA, CargaQ, CargaM, desplaza, 
  //                      clk, reset, resta, output wire [2:0] salida_q, output wire [3:0] salida_a, output wire qsub1);
  camino_datos CD(multiplicando, multiplicador, CargaA, CargaQ, CargaM, desplaza, clk, reset, resta, salida_q, salida_a, qsub1);
  // module unidad_control (input wire q0, qsub1, reset, clk, output wire CargaQ, DesplazaAQ, CargaA, CargaM, Fin);
  unidad_control UC(salida_q, qsub1, reset, clk, CargaQ, desplaza, CargaA, CargaM, resta, Fin);
  assign resultado = {salida_a[2],salida_a[1],salida_a[0],salida_q[2],salida_q[1],salida_q[0]};
endmodule

