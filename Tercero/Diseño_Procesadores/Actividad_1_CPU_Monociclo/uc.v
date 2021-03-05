module uc(input wire [5:0] opcode, 
          input wire z, 
          output reg s_inc, s_inm, we3, wez, 
          output reg [2:0] op_alu);

always @(opcode) begin
  casez (opcode)
    begin
      6b'0000zz: s_inc = 0;
      // 6b'0001zz: 
      

    end 
    default: 
  endcase
  
end

endmodule