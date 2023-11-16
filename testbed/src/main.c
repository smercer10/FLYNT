#include <stdlib.h>
#include <core/logger.h>
#include <core/asserts.h>

int main(void)
{
  F_FATAL("Test message: %d", 1);
  F_ERROR("Test message: %d", 2);
  F_WARN("Test message: %d", 3);
  F_INFO("Test message: %d", 4);
  F_DEBUG("Test message: %d", 5);
  F_TRACE("Test message: %d", 6);

  F_ASSERT(1 == 1);
  F_ASSERT_MSG(1 == 1, "Test failure");
  F_ASSERT_DEBUG(1 == 0);

  return EXIT_SUCCESS;
}
