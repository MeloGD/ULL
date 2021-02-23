module multiplicador (input wire [2:0] multiplicando, multiplicador, input wire clk, reset, output wire [5:0] resultado, output wire Fin);
  // Salida de CD con Q, de la cual cogeremos el q0 para poder pasarlo a la UC y poder controlar que operacion hacer junto con qsub1, que viene del FlipFlop
  wire [2:0] q; 
  wire CargaA, CargaM, CargaQ, desplaza, resta, qsub1;
  // module camino_datos (input wire [2:0] entrada_q, entrada_m, input wire CargaA, CargaQ, CargaM, desplaza, 
  //                      clk, reset, resta, input wire [2:0] salida_q, output wire qsub1);
  camino_datos CD(multiplicador, multiplicando, CargaA, CargaM, CargaQ, desplaza, clk, reset, resta, q, qsub1);
  // module unidad_control (input wire q0, qsub1, reset, clk, output wire CargaQ, DesplazaAQ, CargaA, CargaM, Fin);
  unidad_control UC(q, qsub1, reset, clk, CargaQ, desplaza, CargaA, CargaM, Fin);
endmodule

