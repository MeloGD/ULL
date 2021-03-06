module uc(input wire [15:0] opcode, 
          input wire z, intr1, intr2, 
          output reg s_inc, we3, wez, pop, push, s_stack, we4, we_out, timer_e, s_mem,
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
        s_mem = 1'b0;
        // necesito estos 3 bits del opcode para poder elegir que tipo de operacion
        op_alu = opcode[4:2]; 
        //timer_e = 0;
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
        s_mem = 1'b0;
    end
    
    // Salto
    6'b100100: 
      begin 
        s_inc = 0;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        s_mem = 1'b0;
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
        s_mem = 1'b0;
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
        s_mem = 1'b0;
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
        s_mem = 1'b0;
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
        s_mem = 1'b0;
      end
    // IN IO
    6'b101010:
      begin
        s_inc = 1;
        we3 = 1;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b11;
        op_alu = 3'b000;
        s_in = opcode[9:8];
        we_out = 0;
        s_mem = 1'b0;
      end
    // OUT IO REG
    6'b101011:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        s_in = 2'b00;
        we_out = 1;
        s_out = 2'b00;
        s_mem = 1'b0;
        //s_out = opcode[1:0];
      end
    // OUT IO INM1
    6'b101100:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        s_in = 2'b00;
        we_out = 1;
        s_out = 2'b01;
        s_mem = 1'b0;
        //s_out = opcode[1:0];
      end
    // store mem_data (usando como direccionamiento la memoria de programa)
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
        s_mem = 1'b0;
      end
    // store mem_data  (usando como direccionamiento el banco de registros)
    6'b110000:
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
        s_mem = 1'b1;
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
        timer_e = 0;
        s_mem = 1'b0;
      end
    // Timer (solo usamos este opcode para dejar el resto de señales a 0)
    6'b101111:
      begin
        s_inc = 1;
        we3 = 0;
        wez = 0;
        pop = 0;
        push = 0;
        s_stack = 0;
        we4 = 0;
        s_inm = 2'b00;
        op_alu = 3'b000;
        timer_e = 1;
        s_mem = 1'b0;
      end   
    default:; 
  endcase

endmodule