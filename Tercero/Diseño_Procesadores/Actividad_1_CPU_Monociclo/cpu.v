module cpu(input wire clk, reset, input wire [7:0] in1, in2, output wire [7:0] out1, out2, out3, out4);
//Procesador sin memoria de datos de un solo ciclo

wire s_inc, we3, wez, z, pop, push, s_stack, we4, we_out;
wire [1:0] s_inm, s_in, s_out;
wire [2:0] op_alu;
wire [15:0] opcode;

//module cd(input wire clk, reset, s_inc, we3, wez, popsignal, pushsignal, s_stack, we4,
//          input wire [1:0] s_inm,
//          input wire [2:0] op_alu, 
//          output wire z, output wire [5:0] opcode);
cd camino_datos(clk, reset, s_inc, we3, wez, pop, push, s_stack, we4, we_out,
                s_inm, s_in, s_out,
                op_alu,
                in1, in2, 
                z, opcode, out1, out2, out3, out4);

//module uc(input wire [5:0] opcode, 
//          input wire z, 
//          output reg s_inc, we3, wez, pop, push, s_stack, we4,
//          output reg [1:0] s_inm,
//          output reg [2:0] op_alu);

uc unidad_control(opcode, 
                  z, 
                  s_inc, we3, wez, pop, push, s_stack, we4, we_out,
                  s_inm, s_in, s_out,
                  op_alu);
endmodule
