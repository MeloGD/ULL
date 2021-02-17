
module camino_datos
    wire [3:0] salida_sumador, salida_a;
    wire [2:0] entrada_q, salida_q;
    wire carga, desplaza,clk, reset;
    //module registro4 (input wire [3:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [3:0] salida);
    registro4 A(salida_sumador, salida_a[3], carga, desplaza, clk, reset, salida_a);
    //module registro3 (input wire [2:0] entrada, input wire bit_en_desp, input wire Carga, Desplaza, clk, reset, output wire [2:0] salida);
    registro3 Q(entrada_q, desplaza, salida_a[0], carga, desplaza, reset, salida_q);
    //module registro4
    registro4 M();
endmodule
