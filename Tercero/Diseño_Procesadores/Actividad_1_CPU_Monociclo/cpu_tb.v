`timescale 1 ns  / 10 ps

module cpu_tb;


reg clk, reset, intr1, intr2;
reg [7:0] in1, in2;
wire [7:0] out1, out2, out3, out4;


// generación de reloj clk
always //siempre activo, no hay condición de activación
begin
  clk = 1'b1;
  #20;
  clk = 1'b0;
  #20;
end

initial begin
  intr1 = 1'b0;
  intr2 = 1'b0;
  #(40)
  intr1 = 1'b1;
  #(40)
  intr1  = 1'b0;
end

// instanciación del procesador
cpu micpu(clk, reset, intr1, intr2, in1, in2, out1, out2, out3, out4);

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

  #(9*40);  //Esperamos 9 ciclos o 9 instrucciones
  $finish;
end


endmodule

