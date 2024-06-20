.global _main
.balign 4
_main:

  /*
    Goal: Calcluate inv square root of 2
    using newtons method 

    frsqrts gives us (3 - xz) / 2
    we want (y(3 - xy^2)) / 2
  */
 
  fmov  d0, #2.0  // Gloal compute 1/sqrt(2)
  fmov  d1, #0.5  // initial guess: y


  // first iteration 
  fmul d2, d1, d1     // z = y^2
  frsqrts d3, d0, d2  // (3- xz) /2
  fmul d1, d1, d3     // y = y (3 - xz) / 2

  // second iteration 
  fmul d2, d1, d1     // z = y^2
  frsqrts d3, d0, d2  // (3- xz) /2
  fmul d1, d1, d3     // y = y (3 - xz) / 2

  // third iteration 
  fmul d2, d1, d1     // z = y^2
  frsqrts d3, d0, d2  // (3- xz) /2
  fmul d1, d1, d3     // y = y (3 - xz) / 2


  mov x0,  #0
  mov x16, #1 // terminate syscall
  svc 0x80    // superivsorcall
