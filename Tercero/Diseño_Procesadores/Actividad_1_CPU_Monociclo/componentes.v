//Componentes varios

//Banco de registros de dos salidas y una entrada
module regfile(input  wire        clk, 
               input  wire        we3,           //se�al de habilitaci�n de escritura
               input  wire [3:0]  ra1, ra2, wa3, //direcciones de regs leidos y reg a escribir
               input  wire [7:0]  wd3, 			 //dato a escribir
               output wire [7:0]  rd1, rd2);     //datos leidos

  reg [7:0] regb[0:15]; //memoria de 16 registros de 8 bits de ancho

  initial
  begin
    $readmemb("regfile.dat",regb); // inicializa los registros a valores conocidos
  end  
  
  // El registro 0 siempre es cero
  // se leen dos reg combinacionalmente
  // y la escritura del tercero ocurre en flanco de subida del reloj
  
  always @(posedge clk)
    if (we3) regb[wa3] <= wd3;	
  
  assign rd1 = (ra1 != 0) ? regb[ra1] : 0;
  assign rd2 = (ra2 != 0) ? regb[ra2] : 0;

endmodule

//modulo sumador  
module sum(input  wire [9:0] a, b,
             output wire [9:0] y);

  assign y = a + b;

endmodule

//modulo registro para modelar el PC, cambia en cada flanco de subida de reloj o de reset
module registro #(parameter WIDTH = 8)
              (input wire             clk, reset,
               input wire [WIDTH-1:0] d, 
               output reg [WIDTH-1:0] q);

  always @(posedge clk, posedge reset)
    if (reset) q <= 0;
    else       q <= d;

endmodule


//modulo registro para modelar el PC, cambia en cada flanco de subida de reloj o de reset
module registro_mod #(parameter WIDTH = 8)
              (input wire             clk, reset,
               input wire [WIDTH-1:0] d, 
               output reg [WIDTH-1:0] q);

  always @(negedge clk, posedge reset)
    if (reset) q <= 0;
    else       q <= d;

endmodule


//modulo multiplexor, si s=1 sale d1, s=0 sale d0
module mux2 #(parameter WIDTH = 8)
             (input  wire [WIDTH-1:0] d0, d1, 
              input  wire             s, 
              output wire [WIDTH-1:0] y);

  assign y = s ? d1 : d0; 

endmodule

//modulo multiplexor 4, si s=00 sale d0, s=01 sale d1, s=10 sale d2 y s=11 sale d3
module mux4 #(parameter WIDTH = 8)
             (input  wire [WIDTH-1:0] d0, d1, d2, d3,
              input  wire [1:0] s, 
              output reg [WIDTH-1:0] y);
  // ponemos todas las señales para aumentar la sensibilidad y que s esté preparado a tiempo (se pueda poner a 1)            
  always@(d0 or d1 or d2 or d3 or s)  
    begin
      case (s)
          2'b00: y <= d0;
          2'b01: y <= d1;
          2'b10: y <= d2;
          2'b11: y <= d3;
      endcase
    end
endmodule

//Biestable para el flag de cero
//Biestable tipo D s�ncrono con reset as�ncrono por flanco y entrada de habilitaci�n de carga
module ffd(input wire clk, reset, d, carga, output reg q);

  always @(posedge clk, posedge reset)
    if (reset)
	    q <= 1'b0;
	  else
	    if (carga)
	      q <= d;
endmodule

module stack(input wire clk, reset, popsignal, pushsignal,
            output reg [9:0] pop,
            input wire [9:0] push);
  
  // bus de 10 --> 8 instrucciones para saltos
  reg [9:0] memoria_pila[0:7];
  reg [2:0] stack_pointer;
  // inicializacion del stack pointer a 0
  initial 
    begin
      stack_pointer = 3'b000;
    end
  
  always @(pushsignal, popsignal, posedge reset) begin
    if (reset)
      begin
        stack_pointer = 3'b000;
      end
    if (pushsignal)
      begin
        // cargamos, luego incrementamos
        memoria_pila[stack_pointer] = push;
        stack_pointer = stack_pointer + 3'b001;
      end
    if (popsignal) 
      begin
        //pop = memoria_pila[stack_pointer];
        stack_pointer = stack_pointer - 3'b001;
        pop = memoria_pila[stack_pointer];
      end
      
    // if sp > 8 avisar de error  
  end

endmodule 

//Banco de registros de dos salidas y una entrada
module memory_data(input  wire        clk, 
                   input  wire        we4,      //se�al de habilitaci�n de escritura
                   input  wire [11:0]  ra,       //direcciones leidas 
                   input  wire [7:0]  wd4, 			//dato a escribir
                   output wire [7:0]  rd1);     //datos leidos

  reg [7:0] mem_data[0:63]; //memoria de 64 registros de 8 bits de ancho

  initial
  begin
    $readmemb("memdatafile.dat",mem_data); // inicializa los registros a valores conocidos
  end  
  
  // El registro 0 siempre es cero
  // se leen dos reg combinacionalmente
  // y la escritura del tercero ocurre en flanco de subida del reloj
  
  always @(posedge clk)
    // Donde voy a escribir el dato --> ra[5:0] de la instruccion
    if (we4) mem_data[ra[5:0]] <= wd4;	
  
  // en caso de fallo probar assign rd1 = mem_data[ra];
  // Donde voy a leer el dato
  assign rd1 = (ra != 0) ? mem_data[ra[11:6]] : 0;

endmodule


// Decoder para salida datos
module decoder24(input wire [1:0] in,
               output wire d0, d1, d2, d3);

  assign d0 =  (~in[1] & ~in[0]);
  assign d1 =  (~in[1] & in[0]);
  assign d2 =  (in[1] & ~in[0]);
  assign d3 =  (in[1] & in[0]);
endmodule

// Registros para inte
module interruption1_reg(output wire [9:0] out);
  reg[9:0] intr [1:1];
  initial 
    begin
      $readmemb("intr1_reg.dat", intr);
    end
  assign out = intr[1];
endmodule

module interruption2_reg(output wire [9:0] out);
  reg[9:0] intr [1:1];
  initial 
    begin
      $readmemb("intr2_reg.dat", intr);
    end
  assign out = intr[1];
endmodule