module uc(input wire [5:0] opcode, 
          input wire z, 
          output reg s_inc, s_inm, we3, wez, 
          output reg [2:0] op_alu);

always @(opcode)
casez (opcode)
    6'b000000: 
      begin 
        s_inc = 0;
      end
      // 6b'0001zz: 
    default:; 
  endcase

endmodule