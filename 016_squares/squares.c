int max(int num1, int num2) {
  //check if num1 is greater than num2
  if (num1 > num2) {
    //if so, your answer is num1
    return num1;
  }
  //otherwise, your answer is num2
  else {
    return num2;
  }
}
int is_between(int x, int x1, int x2) {
  if ((x >= x1) && (x < x2))
    return 1;
  else
    return 0;
}

int is_equal(int y, int y1, int y2) {
  if (y == y1 || y == y2)
    return 1;
  else
    return 0;
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  int w;
  int h;
  //compute the max of size1 and (x_offset + size2).  Call this w
  w = max(size1, x_offset + size2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  h = max(size1, y_offset + size2);
  //count from 0 to h. Call the number you count with y
  int x = 0;
  int y = 0;
  for (y = 0; y < h; y++) {
    //count from 0 to w. Call the number you count with x
    for (x = 0; x < w; x++) {
      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
      if ((is_between(x, x_offset, x_offset + size2) &&
           is_equal(y, y_offset, y_offset + size2 - 1)) ||
          (is_between(y, y_offset, y_offset + size2) &&
           is_equal(x, x_offset, x_offset + size2 - 1)))
        printf("*");
      else if (((x < size1) && (is_equal(y, 0, size1 - 1))) ||
               ((y < size1) && (is_equal(x, 0, size1 - 1))))
        printf("#");
      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #
      else
        printf(" ");
      //else print a space
      //when you finish counting x from 0 to w,
    }
    //print a nexwline
    printf("\n");
  }
}
