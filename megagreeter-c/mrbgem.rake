MRuby::Gem::Specification.new('megagreeter-c') do |spec|
  spec.license = 'MIT'
  spec.author = 'Tatsushi Demachi'
  spec.summary = 'MegaGreeter, mruby gem example with C code'

  spec.add_dependency 'mruby-print', core: 'mruby-print'
end
