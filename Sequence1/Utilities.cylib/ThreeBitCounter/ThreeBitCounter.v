
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

module ThreeBitCounter (clock, reset, enable, counter_out);
input clock, reset, enable;
output [2:0] counter_out;

reg [2:0] counter_out;

always @(posedge clock)
begin: COUNTER
    if (reset == 1'b1) begin
    counter_out <= 3'b000;
    end
    else if (enable == 1'b1) begin
    counter_out <= counter_out + 1;
    end
end    
endmodule


