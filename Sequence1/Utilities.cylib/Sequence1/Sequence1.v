
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 07/31/2024 at 14:11
// Component: Sequence1
module Sequence1 (
	output reg Count_Enable,
	output reg Rest_Pos,
	output reg Work_Pos,
	input   CLK,
	input   R_Sensor,
	input   Start_Input,
	input   W_Sensor
);
reg [2:0] state;
reg [2:0] count;

localparam S0 = 3'b000;
localparam S1 = 3'b001;
localparam S2 = 3'b010;
localparam S3 = 3'b011;
localparam S4 = 3'b100;

initial
begin
  state <= S0;
  count <= 3'd0;
  Rest_Pos <= 1'b1;
  Work_Pos <= 1'b0;
  Count_Enable <= 1'b0;
end

always @(posedge CLK)
begin
case (state)
S0:
  if (Start_Input) begin
  state <= S1;
  Rest_Pos <= 1'b0;
  Work_Pos <= 1'b1;
  Count_Enable <= 1'b0;
end
  else state <= S0;

S1:
  if (!R_Sensor) begin
    if (W_Sensor) begin
    state <= S2;
    Rest_Pos <= 1'b1;
    Work_Pos <= 1'b0;
    Count_Enable <= 1'b1;
end
  else state <= S1;
end

S2:
if (R_Sensor) begin
    if (!W_Sensor) begin
    state <= S3;
    Rest_Pos <= 1'b0;
    Work_Pos <= 1'b1;
    Count_Enable <= 1'b0;
end
else state <= S2;
end

S3:
if (!R_Sensor) begin
    if (W_Sensor) begin
    state <= S4;
    Rest_Pos <= 1'b1;
    Work_Pos <= 1'b0;
    Count_Enable <= 1'b1;
end
else state <= S3;
end

S4:
if (R_Sensor) begin
    if (!W_Sensor) begin
    state <= S0;
    Rest_Pos <= 1'b1;
    Work_Pos <= 1'b1;
   // Count_Enable <= 1'b0;
end
else state <= S4;
end
endcase
end

endmodule

