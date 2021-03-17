module uc(input wire [5:0] opcode, 
          input wire z, 
          output reg s_inc, we3, wez, pop, push, s_stack, we4,
          output reg [1:0] s_inm,
          output reg [2:0] op_alu);

always @(opcode)
casez (opcode)

    // Operaciones arimeticas o logicas
    6'b0zzzzz:
      begin
        // necesito estos 3 bits del opcode para poder elegir que tipo de operacion
        op_alu = opcode[4:2]; 
        wez = 1; // donde unico tenemos que activar el flag de cero
        s_inc = 1;
        s_inm = 2'b00; // para poder cargar el valor que sale de la alu en el mux
        we3 = 1 ; // habilito la escritura en el banco de registros
        s_stack = 0;
        push = 0;
        pop = 0;
      end

    // Carga de constante inmediata, las cargas escriben en el banco de registros
    // con 10zzzz ya es sufiente para diferenciarlo, no hace falta escribir más nºs  
    6'b10zzzz:
      begin
        s_inm = 2'b01;
        s_inc = 1;
        we3 = 1;
        s_stack = 0;
        push = 0;
        pop = 0;
    end
    
    // Salto
    6'b110000: 
      begin 
        s_inc = 0;
        s_stack = 0;
        push = 0;
        pop = 0;
      end
    // Salto Z
    6'b110001: 
      begin 
        if (z == 1) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
        s_stack = 0;
        push = 0;
        pop = 0;
      end  
    // Salto No Z
    6'b110010:
      begin 
        if (z == 0) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
        push = 0;
        pop = 0;
        s_stack = 0;
      end
    // Subrutinas - Pila
    // pop
    6'b111100:
      begin
        s_inc = 0;
        s_stack = 1;
        pop = 1;
        push = 0;
        we3 = 0;
        wez = 0;
      end     
    // push
    6'b111000:
      begin
        s_inc = 1;
        s_stack = 0;
        push = 1;
        pop = 0;
        we3 = 0;
        wez = 0;
      end
    // load mem_data
    6'b111010:
    // store mem_data 
    6'b111011: 
    default:; 
  endcase

endmodule