MRuby::Gem::Specification.new('megagreeter') do |spec|
  spec.license = 'MIT'
  spec.author = 'Tatsushi Demachi'
  spec.summary = 'MegaGreeter, mruby gem example'

  spec.add_dependency 'mruby-print', core: 'mruby-print'
end
