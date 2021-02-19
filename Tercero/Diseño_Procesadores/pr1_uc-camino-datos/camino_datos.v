
module camino_datos
    wire [3:0] salida_sumador, salida_a, salida_m;
    wire [2:0] entrada_q, salida_q, entrada_m;
    wire carga, desplaza,clk, reset, resta;
    reg q;
    //module registro4 (input wire [3:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [3:0] salida);
    registro4 A(salida_sumador, salida_a[3], carga, desplaza, clk, reset, salida_a);
    //module registro3 (input wire [2:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [2:0] salida);
    registro3 Q(entrada_q, salida_a[0], carga, desplaza, clk, reset, salida_q);
    //module registro4
    registro4 M({entrada_m[2], entrada_m}, 0, carga, desplaza, clk, reset, salida_m);
    //module sum_resta4(output wire[3:0] S, output wire c_out, input wire[3:0] A, input wire[3:0] B, input wire resta);
    sum_resta4 Sumador(salida_sumador, , salida_a, salida_m, resta);
    //Q-1 --> representado con un FlipFlop D
    //module ffdc (input wire clk, reset, carga, d, output reg q);
    ffdc #(0) Qmenos1(clk, reset, carga, salida_q[0] , q);

endmodule

// ¿por qué el ffd para Qmenos1?
// ¿no debería de haber un 0 en el desplaza de M? 
// assign funcionamiento sumador 