#include <gtest/gtest.h>
#include <stdlib.h> // Include for calloc and free

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *result = disemvowel((char*) "");
  ASSERT_STREQ("", result);
  free(result); // Free the allocated memory
}

TEST(Disemvowel, HandleNoVowels) {
  char *result = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", result);
  free(result); // Free the allocated memory
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *result = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", result);
  free(result); // Free the allocated memory
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *result = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", result);
  free(result); // Free the allocated memory
}

TEST(Disemvowel, HandlePunctuation) {
  char *result = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", result);
  free(result); // Free the allocated memory
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *result = disemvowel(str);
  ASSERT_STREQ("xyz", result);

  free(result); // Free the allocated memory
  free(str); // Free the allocated memory
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}