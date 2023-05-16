#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src))) {
    result =
        (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src, start_index);
      s21_strcat(result, str);
      s21_strcat(result, src + start_index);
    }
  }
  return result;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  void *out = s21_NULL;
  for (s21_size_t i = 0; i < n && s; i++) {
    if (*s == (unsigned char)c) {
      out = s;
      break;
    }
    s++;
  }
  return out;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *d = (unsigned char *)str1;
  unsigned char *s = (unsigned char *)str2;
  int dev = 0;
  for (s21_size_t i = 0; i < n; i++) {
    dev = *d - *s;
    if (*d != *s) {
      break;
    }
    d++;
    s++;
  }
  return dev;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *destCopy = (char *)dest;
  const char *srcCopy = (const char *)src;

  while (n != 0) {
    *destCopy = *srcCopy;
    destCopy++, srcCopy++;
    n--;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  unsigned char *s = (unsigned char *)src;
  char *res = (char *)malloc(sizeof(char) * n);
  if (res) {
    s21_memcpy(res, s, n);
    s21_memcpy(d, res, n);
    free(res);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  while (n--) *s++ = (unsigned char)c;
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  s21_strcpy(dest + s21_strlen(dest), src);
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *dev = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      dev = (char *)str + i;
      break;
    }
  }
  return dev;
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0, i = 0;
  if (str1 && str2) {
    while (str1[i] && str1[i] == str2[i]) {
      i++;
    }
    res = str1[i] - str2[i];
  }
  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) dest[i] = src[i];
  dest[s21_strlen(src)] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (const char *i = str1; *i; i++) {
    unsigned short flag = 0;
    for (const char *j = str2; *j; j++) {
      if (*i == *j) {
        // count++;
        flag = 1;
        break;
      }
    }
    if (flag)
      break;
    else
      count++;
  }
  return count;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str) {
    for (int i = 0; str[i]; i++) {
      len++;
    }
  }
  return (len);
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  long unsigned int src_len = s21_strlen(src);
  long unsigned int dest_len = s21_strlen(dest);
  char *ptr = dest + dest_len;
  long unsigned int counter = 1;
  while ((counter <= n && counter <= src_len) && *src != '\0') {
    *ptr++ = *src++;
    counter++;
  }
  *ptr = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; src[i] != '\0' && i < n; i++) {
    dest[i] = src[i];
  }
  if (src[i] == '\0' && n > 0 && n > s21_strlen(src)) {
    dest[i] = '\0';
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  for (const char *i = str1; *i; i++) {
    for (const char *j = str2; *j; j++) {
      if (*i == *j) {
        result = (char *)i;
        break;
      }
    }
    if (result) break;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *dev = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      dev = (char *)str + i;
    }
  }
  return dev;
}

void s21_strspn_revers(const char **src, const char *trim_chars,
                       s21_size_t *len, const s21_size_t chars_len) {
  s21_size_t m = 0;
  s21_size_t i = (*len) - 1;
  while (src && m != chars_len) {
    if ((*src)[i] == trim_chars[m]) {
      i--;
      (*len)--;
      m = 0;
      continue;
    }
    m++;
  }
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (const char *i = str1; *i; i++) {
    unsigned short flag = 0;
    for (const char *j = str2; *j; j++) {
      if (*i == *j) {
        count++;
        flag = 1;
        break;
      }
    }
    if (!flag) break;
  }
  return count;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  if (needle[0] == '\0') {
    result = (char *)haystack;
  } else {
    int found = 0;
    for (int i = 0; haystack[i] && !found; i++) {
      int flag = 1;
      if (haystack[i] == needle[0]) {
        for (int j = 0; needle[j] && flag; j++) {
          if (haystack[i + j] != needle[j]) {
            flag = 0;
          } else if (needle[j + 1] == '\0') {
            result = (char *)(haystack + i);
            found = 1;
          }
        }
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *dev = s21_NULL;
  if (str) dev = str;
  if (dev) {
    str = dev + s21_strspn(dev, delim);
    dev = str + s21_strcspn(str, delim);
    if (*dev != '\0') {
      *dev = '\0';
      dev++;
    }
  }
  return *str != '\0' ? str : s21_NULL;
}

void *s21_to_lower(const char *str) {
  char *str_regist = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t n = s21_strlen(str);
    str_regist = (char *)malloc(sizeof(char) * (n + 1));
    if (str_regist) {
      for (s21_size_t i = 0; i <= n; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
          str_regist[i] = str[i] + 32;
        else
          str_regist[i] = str[i];
    }
  }
  return str_regist;
}

void *s21_to_upper(const char *str) {
  char *str_regist = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t n = s21_strlen(str);
    str_regist = (char *)malloc(sizeof(char) * (n + 1));
    if (str_regist) {
      for (s21_size_t i = 0; i <= n; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
          str_regist[i] = str[i] - 32;
        else
          str_regist[i] = str[i];
    }
  }
  return str_regist;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src != s21_NULL) {
    if (trim_chars == NULL || trim_chars[0] == '\0') {
      trim_chars = " ";
    }
    int size = (int)s21_strlen(src);
    if (size != 0) {
      int start = -1, end = -1;
      int flag_i = 1, flag_j = 1;
      for (int i = 0, j = size - 1; i < size; i++, j--) {
        if (s21_strchr(trim_chars, src[i]) == s21_NULL && flag_i) {
          start = i;
          flag_i = 0;
        }
        if (s21_strchr(trim_chars, src[j]) == s21_NULL && flag_j) {
          end = j;
          flag_j = 0;
        }
        if (!flag_i && !flag_j) {
          break;
        }
      }
      result = calloc(end - start + 2, sizeof(char));
      if (result != s21_NULL) {
        for (int i = start, j = 0; i <= end; i++, j++) {
          result[j] = src[i];
        }
      }
    } else {
      result = calloc(2, sizeof(char));
      result[0] = '\0';
    }
  }
  return result;
}

#define ERRLEN 50
#if defined(__APPLE__) || defined(__MACH__)
#define UNKNOWN "Unknown error:"
#define ERRCOUNT 107
#else
#define UNKNOWN "No error information"
#define ERRCOUNT 134
#endif

#if defined(__APPLE__) || defined(__MACH__)
static const char s21_errlist[ERRCOUNT][ERRLEN] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif
#if defined(__linux__)
static const char s21_errlist[ERRCOUNT][ERRLEN] = {
    "No error information",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "I/O error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child process",
    "Resource temporarily unavailable",
    "Out of memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "No file descriptors available",
    "Not a tty",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Invalid seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Domain error",
    "Result not representable",
    "Resource deadlock would occur",
    "Filename too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Symbolic link loop",
    "No error information",
    "No message of desired type",
    "Identifier removed",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "Device not a stream",
    "No data available",
    "Device timeout",
    "Out of streams resources",
    "No error information",
    "No error information",
    "No error information",
    "Link has been severed",
    "No error information",
    "No error information",
    "No error information",
    "Protocol error",
    "Multihop attempted",
    "No error information",
    "Bad message",
    "Value too large for data type",
    "No error information",
    "File descriptor in bad state",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "Illegal byte sequence",
    "No error information",
    "No error information",
    "No error information",
    "Not a socket",
    "Destination address required",
    "Message too large",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address in use",
    "Address not available",
    "Network is down",
    "Network unreachable",
    "Connection reset by network",
    "Connection aborted",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is connected",
    "Socket not connected",
    "Cannot send after socket shutdown",
    "No error information",
    "Operation timed out",
    "Connection refused",
    "Host is down",
    "Host is unreachable",
    "Operation already in progress",
    "Operation in progress",
    "Stale file handle",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "Remote I/O error",
    "Quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "No error information",
    "No error information",
    "No error information",
    "No error information",
    "Previous owner died",
    "State not recoverable",
    "No error information",
    "No error information"};
#endif
char *s21_strerror(int errnum) {
  static char res[BUFF_SIZE] = {'\0'};
  if (errnum < 0 || errnum >= ERRCOUNT) {
#ifdef APPLE
    s21_sprintf(res, "%s %d", UNKNOWN, errnum);
#elif linux
    s21_sprintf(res, "%s", UNKNOWN);
#endif
  } else
    s21_strcpy(res, s21_errlist[errnum]);

  return res;
}