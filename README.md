naruby #1 mruby example
=======================

This is a mruby mrbgem example repository written for [naruby #1](https://naruby.connpass.com/event/70718/) (in Japanese). You can compile Ruby only or C and Ruby hybrid mrbgem by doing followings

```shellsession
$ cd path/to/mruby/dir
$ vi build_config.rb # edit the file by any editors you like
#### add "conf.gem 'path/to/mrbgem/dir'" to appropriate place in build_config.rb
$ ./minirake
$ ./build/host/bin/mirb # try compiled mrbgem code
```

This repository has 2 mrbgems

- megagreeter: implements `MegaGreeter` class with `say_hi` and `say_bye` methods written only in Ruby.
- megagreeter-c: adds `say_hi_by_c` method written in C to above. This method works as same as `say_hi`.

The Ruby code is taken from [Ruby in Twenty Minutes](https://www.ruby-lang.org/en/documentation/quickstart/) so it is under the same license as the doc. The C code is under the MIT license.
