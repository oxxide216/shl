#ifndef SHL_LOG_H
#define SHL_LOG_H

#include <stdio.h>

#ifdef NDEBUG

#ifdef SHL_LOG_UWU

#ifdef EMSCRIPTEN
#define PERROR(prefix, ...) fprintf(stderr, prefix "[OWOops] " __VA_ARGS__)
#define PWARN(prefix, ...) fprintf(stderr, prefix "[UWUARN] " __VA_ARGS__)
#define PINFO(prefix, ...) printf(prefix "[INUWUO] " __VA_ARGS__)
#else
#define PERROR(prefix, ...) fprintf(stderr, prefix "\033[35;1m[OWOops]\033[0m " __VA_ARGS__)
#define PWARN(prefix, ...) fprintf(stderr, prefix "\033[33;1m[UWUARN]\033[0m " __VA_ARGS__)
#define PINFO(prefix, ...) printf(prefix "\033[1m[INUWUO]\033[0m " __VA_ARGS__)
#endif

#else

#ifdef EMSCRIPTEN
#define PERROR(prefix, ...) fprintf(stderr, prefix "[ERROR] " __VA_ARGS__)
#define PWARN(prefix, ...) fprintf(stderr, prefix "[WARN] " __VA_ARGS__)
#define PINFO(prefix, ...) printf(prefix "[INFO] " __VA_ARGS__)
#else
#define PERROR(prefix, ...) fprintf(stderr, prefix "\033[31;1m[ERROR]\033[0m " __VA_ARGS__)
#define PWARN(prefix, ...) fprintf(stderr, prefix "\033[33;1m[WARN]\033[0m " __VA_ARGS__)
#define PINFO(prefix, ...) printf(prefix "\033[1m[INFO]\033[0m " __VA_ARGS__)
#endif

#endif // SHL_LOG_UWU

#else

#ifdef SHL_LOG_UWU

#ifdef EMSCRIPTEN
#define PERROR(prefix, ...)                          \
  do {                                               \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);     \
    fprintf(stderr, prefix "[OWOops] " __VA_ARGS__); \
  } while (0)
#define PWARN(prefix, ...)                           \
  do {                                               \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);    \
    fprintf(stderr, prefix "[UWUARN] " __VA_ARGS__); \
  } while (0)
#define PINFO(prefix, ...)                  \
  do {                                      \
    printf(__FILE__ ":%d: ", __LINE__);     \
    printf(prefix "[INUWUO] " __VA_ARGS__); \
  } while(0)
#else
#define PERROR(prefix, ...)                                           \
  do {                                                                \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);                      \
    fprintf(stderr, prefix "\033[35;1m[OWOops]\033[0m " __VA_ARGS__); \
  } while (0)
#define PWARN(prefix, ...)                                            \
  do {                                                                \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);                     \
    fprintf(stderr, prefix "\033[33;1m[UWUARN]\033[0m " __VA_ARGS__); \
  } while (0)
#define PINFO(prefix, ...)                                \
  do {                                                    \
    printf(__FILE__ ":%d: ", __LINE__);                   \
    printf(prefix "\033[1m[INUWUO]\033[0m " __VA_ARGS__); \
  } while(0)
#endif // EMSCRIPTEN

#else

#ifdef EMSCRIPTEN
#define PERROR(prefix, ...)                         \
  do {                                              \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);    \
    fprintf(stderr, prefix "[ERROR] " __VA_ARGS__); \
  } while (0)
#define PWARN(prefix, ...)                           \
  do {                                               \
    fprintf(stderr, __FILE__ ":%d:  ", __LINE__);    \
    fprintf(stderr, prefix ": [WARN] " __VA_ARGS__); \
  } while (0)
#define PINFO(prefix, ...)                              \
  do {                                                  \
    printf(__FILE__ ":%d: ", __LINE__);                 \
    printf(prefix "[INFO] " __VA_ARGS__); \
  } while(0)
#else
#define PERROR(prefix, ...)                                           \
  do {                                                                \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);                      \
    fprintf(stderr, prefix "\033[31;1m[ERROR]\033[0m " __VA_ARGS__);  \
  } while (0)
#define PWARN(prefix, ...)                                              \
  do {                                                                  \
    fprintf(stderr, __FILE__ ":%d: ", __LINE__);                       \
    fprintf(stderr, prefix "\033[33;1m[WARN]\033[0m " __VA_ARGS__);   \
  } while (0)
#define PINFO(prefix, ...)                              \
  do {                                                  \
    printf(__FILE__ ":%d: ", __LINE__);                 \
    printf(prefix "\033[1m[INFO]\033[0m " __VA_ARGS__); \
  } while(0)
#endif // EMSCRIPTEN

#endif // SHL_LOG_UWU

#endif // DEBUG

#define ERROR(...) PERROR("", __VA_ARGS__)
#define WARN(...) PWARN("", __VA_ARGS__)
#define INFO(...) PINFO("", __VA_ARGS__)

#endif // SHL_LOG_H
