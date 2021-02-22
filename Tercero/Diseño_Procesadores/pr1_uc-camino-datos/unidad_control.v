module unidad_control (input wire q0, reset, clk, output wire CargaQ, DesplazaQ, ResetA, CargaA, Fin)
  // Variables reg que almacenan el estado actual y el siguiente
  reg [2:0] estado, estado_siguiente;

  // Codificación de estados
  parameter S0 = 3'b000;
  parameter S1 = 3'b001;
  parameter S2 = 3'b010;
  parameter S3 = 3'b011;
  parameter S4 = 3'b100;
  parameter S5 = 3'b101;
  parameter S6 = 3'b110;
  parameter S7 = 3'b111;

  // Cambios en flacos de subida de clk o reset
  always @(posedge clk, posedge reset)
    if (reset)
        state <= S0;
    else
        state <= estado_siguiente;
  end

  // Funcion de transicion
  always @(*)
    case (estado)
      S0: estado_siguiente = S1; 
      S1: estado_siguiente = S2; 
      S2: estado_siguiente = S3; 
      S3: estado_siguiente = S4; 
      S4: estado_siguiente = S5; 
      S5: estado_siguiente = S6; 
      S6: estado_siguiente = S7; 
      S7: estado_siguiente = S7; 
      default: estado_siguiente = S0;
    endcase
  end

  // Funcion de salida
  assign CargaQ = (estado == S0) ? 1:0;
  assign DesplazaQ = ((estado == S2) | (estado == S4) | (estado == S6)) ? 1:0;
  assign ResetA = (estado == S0) ? 1:0;
  assign CargaA;
  assign Fin;
    

end module