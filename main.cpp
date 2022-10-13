#include <cstring>
#include <iostream>

#include "fmt/core.h"

extern "C" {
#include "zuo/zuo.h"
}

static zuo_ext_t *random_five(zuo_ext_t *args) { return zuo_ext_integer(5); }

auto main(int argc, char **argv) -> int {
  const char *prog = "#lang zuo/kernel (hash 'number (random-five))";
  zuo_ext_t *ht, *v, *qh;

  /* Step 1 */
  zuo_ext_primitive_init();
  zuo_ext_add_primitive(random_five, 1, "random-five");

  /* Step 2 */
  zuo_ext_image_init(NULL);

  /* Step 3 */
  zuo_ext_runtime_init(zuo_ext_false(), zuo_ext_empty_hash());

  qh = zuo_ext_cons(zuo_ext_symbol("quote"),
                    zuo_ext_cons(zuo_ext_symbol("five-app"), zuo_ext_null()));
  /* Run `prog`: */
  ht = zuo_ext_eval_module(qh, prog, strlen(prog));

  /* Inspect the result: */
  v = zuo_ext_hash_ref(ht, zuo_ext_symbol("number"), zuo_ext_false());
  if (zuo_ext_apply(zuo_ext_hash_ref(zuo_ext_kernel_env(),
                                     zuo_ext_symbol("integer?"),
                                     zuo_ext_false()),
                    zuo_ext_cons(v, zuo_ext_null())) == zuo_ext_true()) {

    fmt::print("The answer was {}\n", (int)zuo_ext_integer_value(v));
  } else {
    fmt::print("Something went wrong!\n");
  }

  return 0;
}
