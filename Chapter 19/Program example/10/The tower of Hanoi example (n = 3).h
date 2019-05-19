Move(3, A, C, B)
{
  Move(2, A, B, C)
  {
    Move(1, A, C, B)
    {
      Move(0, A, B, C)
      {
        n == 0, return;
      }
      
      Display("Move a disc from A to C");
      
      Move(0, C, B, A)
      {
        n == 0, return;
      }
    }
    
    Display("Move a disc from A to B");
    
    Move(1, C, B, A)
    {
      Move(0, C, A, B)
      {
        n == 0, return;
      }
      
      Display("Move a disc from C to B");
      
      Move(0, A, B, C)
      {
        n == 0, return;
      }
    }
  }
  
  Display("Move a disc from A to C");
  
  Move(2, B, C, A)
  {
    Move(1, B, A, C)
    {
      Move(0, B, C, A);
      
      Display("Move a disc from B to A");
      
      Move(0, A, C, B);
    }
    
    Display("Move a disc from B to C");
    
    Move(1, A, C, B)
    {
      Move(0, A, B, C);
      
      Display("Move a disc from A to C");
      
      Move(0, B, C, A);
    }
  }
}