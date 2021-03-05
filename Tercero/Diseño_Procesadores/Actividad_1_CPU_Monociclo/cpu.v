module cpu(input wire clk, reset);
//Procesador sin memoria de datos de un solo ciclo

wire s_inc, s_inm, we3, wez, z;
wire [2:0] op_alu;
wire [5:0] opcode;

// module cd(input wire clk, reset, s_inc, s_inm, we3, wez, 
//          input wire [2:0] op_alu, 
//          output wire z, output wire [5:0] opcode);
cd camino_datos(clk, reset, s_inc, s_inm, we3, wez, op_alu, z, opcode);

// module uc(input wire [5:0] opcode, 
//          input wire z, 
//          output reg s_inc, s_inm, we3, wez, 
//          output reg [2:0] op_alu);
uc unidad_control(opcode, z, s_inc, s_inm, we3, wez, op_alu);

endmodule
