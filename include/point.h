#if !defined(POINT_H)
#define POINT_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct point {
  float x;
  float y;
} point_t;

void
point_print(point_t* x);

#if defined(__cplusplus)
}
#endif

#endif /* POINT_H */
