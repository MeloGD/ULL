module uc(input wire [15:0] opcode, 
          input wire z, 
          output reg s_inc, we3, wez, pop, push, s_stack, we4, we_out,
          output reg [1:0] s_inm, s_in, s_out,
          output reg [2:0] op_alu);

always @(opcode)
casez (opcode)
    // Operaciones arimeticas o logicas
    6'b0zzzzz:
      begin
        // donde unico tenemos que activar el flag de cero
        s_inc = 1;
        we3 = 1 ;
        wez = 1; 
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00; 
        // necesito estos 3 bits del opcode para poder elegir que tipo de operacion
        op_alu = opcode[4:2]; 
      end

    // Carga de constante inmediata, las cargas escriben en el banco de registros  
    6'b1000zz:
      begin
        s_inc = 1;
        we3 = 1;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b01;
        op_alu = 3'b000; 
    end
    
    // Salto
    6'b100100: 
      begin 
        s_inc = 0;
        we3 = 1;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
      end
    // Salto Z
    6'b100101: 
      begin 
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        if (z == 1) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
      end  
    // Salto No Z
    6'b100110:
      begin 
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        if (z == 0) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
      end
    // Subrutinas - Pila
    // pop
    6'b101000:
      begin
        s_inc = 0;
        pop = 1;
        push = 0;
        s_stack = 1;
        we3 = 0;
        wez = 0;
      end     
    // push
    6'b101001:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 1;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
      end
    // IN IO
    6'b101010:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 1;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b11;
        op_alu = 3'b000;
        s_in = opcode[9:8];
        we_out = 0;
      end
    // OUT IO
    6'b101011:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 1;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b11;
        op_alu = 3'b000;
        s_in = 2'b00;
        we_out = 1;

      end
    // store mem_data (desde el banco de registros a la memoria de datos)
    6'b1110zz:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 1;
        s_inm = 2'b00;
        op_alu = 3'b000;
      end
    // load mem_data (desde la memoria de datos al banco de registros)
    6'b1111zz:
      begin
        s_inc = 1;
        we3 = 1;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b10;
        op_alu = 3'b000;
      end 
    default:; 
  endcase

endmodule