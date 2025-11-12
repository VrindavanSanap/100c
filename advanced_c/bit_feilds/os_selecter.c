#include <stdio.h>
typedef enum {
  FEAR_TECH = (1 << 0),
  DADY_RICH = (1 << 1),
  WANT_PRIVACY = (1 << 2),
  HAVE_LIFE = (1 << 3),
} os_param_flags;

const char *which_os_should_you_use(const os_param_flags os_param_flag) {
  const int MACOS_FLAGS = FEAR_TECH | DADY_RICH;
  const int CHROME_OS_FLAGS = FEAR_TECH;
  const int UBUNTU_FLAGS = WANT_PRIVACY | HAVE_LIFE;
  const int ARCH_FLAGS = WANT_PRIVACY;
  if (MACOS_FLAGS & os_param_flag) {
    return "Use macos become a itodler";
  }
  if (CHROME_OS_FLAGS & os_param_flag) {
    return "Use Chrome OS, sell your soul to ads";
  }
  if (UBUNTU_FLAGS & os_param_flag) {
    return "Use Ubuntu, become a basement-dwelling neckbeard";
  }
  if (ARCH_FLAGS & os_param_flag) {
    return "Use Arch Linux, become a masochistic archivist";
  }
  return "Use Windows, become a corporate drone";
}
int main() {
  const char *my_os = which_os_should_you_use(HAVE_LIFE | WANT_PRIVACY);
  printf("%s\n", my_os);
  return 0;
}