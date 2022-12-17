#include <stdio.h>
#include <assert.h>

// void not_what_you_want(int array[]) {
//   printf("%zu\n", sizeof array);
//
//   printf("%p %p\n", array, &array);
// }

int main() {
  int array[] = {1, 2, 3, 4, 5};
  int *ap = array;
  int (*ap2)[] = &array;

  // sizeof array == 20, sizeof ap == 8, sizeof ap2 == 8, sizeof *ap2
  printf("sizeof array == %zu, sizeof ap == %zu, sizeof ap2 == %zu, sizeof *ap2\n",
         sizeof array, sizeof ap, sizeof ap2);

  // 0x7ffc7733d890 0x7ffc7733d890 0x7ffc7733d890 0x7ffc7733d880 0x7ffc7733d890 0x7ffc7733d888
  printf("%p %p %p %p %p %p\n", array, &array, ap, &ap, ap2, &ap2);

  int n = sizeof array / sizeof * array;
  for (int i=0; i<n; i++) {
    assert(array[i] == ap[i]);
    assert(array + i == ap + i);
    assert(*(array + i) == *(ap + i));
  }
}
