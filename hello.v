module main;

    initial
        begin
           $display("I love William.");
           $finish;
        end
        
endmodule

//Compile: % iverilog -o hello hello.v
//Run: % vvp hello
