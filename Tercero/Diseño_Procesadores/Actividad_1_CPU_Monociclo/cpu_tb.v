`timescale 1 ns  / 10 ps

module cpu_tb;


reg clk, reset;
reg [7:0] in1, in2;
wire [7:0] out1, out2, out3, out4;


// generación de reloj clk
always //siempre activo, no hay condición de activación
begin
  clk = 1'b1;
  #30;
  clk = 1'b0;
  #30;
end

// instanciación del procesador
cpu micpu(clk, reset, in1, in2, out1, out2, out3, out4);

initial
begin
  $dumpfile("cpu_tb.vcd");
  $dumpvars;
  // añadir nuevo dumpvars
  //$dumpvars(0,cpu_tb.cpu.cd.regfile[1]);
  reset = 1;  //a partir del flanco de subida del reset empieza el funcionamiento normal
  #10;
  reset = 0;  //bajamos el reset 
end

initial
begin

  #(9*60);  //Esperamos 9 ciclos o 9 instrucciones
  $finish;
end


endmodule