module uc(input wire [5:0] opcode, 
          input wire z, 
          output reg s_inc, s_inm, we3, wez, 
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
        s_inm = 0; // para poder cargar el valor que sale de la alu en el mux
        we3 = 1 ; // habilito la escritura en el banco de registros
      end

    // Carga de constante inmediata, las cargas escriben en el banco de registros
    // con 10zzzz ya es sufiente para diferenciarlo, no hace falta escribir más nºs  
    6'b10zzzz:
      begin
        s_inm = 1;
        s_inc = 1;
        we3 = 1;
    end
    
    // Salto
    6'b110000: 
      begin 
        s_inc = 0;
      end
    // Salto Z
    6'b110001: 
      begin 
        if (z == 1) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
      end  
    // Salto No Z
    6'b110010:
      begin 
        if (z == 0) begin
          s_inc = 0;
        end else begin
          s_inc = 1;
        end
      end   
      
    default:; 
  endcase

endmodule