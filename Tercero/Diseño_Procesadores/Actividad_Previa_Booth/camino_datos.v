
module camino_datos (input wire [2:0] entrada_m, entrada_q, input wire CargaA, CargaQ, CargaM, desplaza, 
                     clk, reset, resta, output wire [2:0] salida_q, output wire [3:0] salida_a, output wire qsub1);
  // Cables/buses internos
  wire [3:0] salida_sumador, salida_m;
  assign carga_qsub1 = CargaQ | desplaza;
  //module registro4 (input wire [3:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [3:0] salida);
  registro4 A(salida_sumador, salida_a[3], CargaA, desplaza, clk, reset, salida_a);
  //module registro3 (input wire [2:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [2:0] salida);
  registro3 Q(entrada_q, salida_a[0], CargaQ, desplaza, clk, reset, salida_q);
  //module registro4
  registro4 M({entrada_m[2], entrada_m}, 1'b0, CargaM, 1'b0, clk, reset, salida_m);
  //module sum_resta4(output wire[3:0] S, output wire c_out, input wire[3:0] A, input wire[3:0] B, input wire resta);
  sum_resta4 Sumador(salida_sumador, , salida_a, salida_m, resta);
  //Q-1 --> representado con un FlipFlop D
  //module ffdc (input wire clk, reset, carga, d, output reg q);
  ffdc Qmenos1(clk, reset, carga_qsub1, salida_q[0] , qsub1);
  // preguntar si en el campo input d se puede poner salida_q[0]
  
  // con los assign, no hace falta que resultado sea tipo reg, si fuera un bloque always o similar, si
  //assign resultado = {salida_a[2:0],salida_q};
endmodule

