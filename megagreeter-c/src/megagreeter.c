#include "mruby.h"
#include "mruby/array.h"
#include "mruby/proc.h"
#include "mruby/string.h"
#include "mruby/value.h"
#include "mruby/variable.h"
#include <stdio.h>

static mrb_value
mrb_megagreeter_c_each_block(mrb_state *mrb, mrb_value obj)
{
  mrb_value name;
  mrb_get_args(mrb, "o", &name);
  name = mrb_obj_as_string(mrb, name);
  printf("Hello %s! I'm C extension\n", mrb_str_to_cstr(mrb, name));
  return mrb_nil_value();
}

static mrb_value
mrb_megagreeter_c_say_hi_by_c(mrb_state *mrb, mrb_value self)
{
  mrb_value res = mrb_nil_value();
  mrb_value names, proc;
  struct RProc *blk;

  names = mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@names"));
  if (mrb_nil_p(names)) {
    puts("...");
  } else if (mrb_respond_to(mrb, names, mrb_intern_lit(mrb, "each"))) {
    blk = mrb_proc_new_cfunc(mrb, mrb_megagreeter_c_each_block);
    proc = mrb_obj_value(blk);
    res = mrb_funcall_with_block(mrb, names, mrb_intern_lit(mrb, "each"), 0, NULL, proc);
  } else {
    names = mrb_obj_as_string(mrb, names);
    printf("Hello %s! I'm C extension\n", mrb_str_to_cstr(mrb, names));
  }
  return res;
}

void
mrb_megagreeter_c_gem_init(mrb_state *mrb)
{
  struct RClass *megagreeter_class = mrb_define_class(mrb, "MegaGreeter", mrb->object_class);
  mrb_define_method(mrb, megagreeter_class, "say_hi_by_c", mrb_megagreeter_c_say_hi_by_c, MRB_ARGS_NONE());
}

void
mrb_megagreeter_c_gem_final(mrb_state *mrb)
{
  /* finalize */
}
