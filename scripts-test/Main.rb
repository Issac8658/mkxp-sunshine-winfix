begin
  $console = Graphics.fullscreen
  Graphics.frame_rate = 60
  Font.default_size = 20
  print("Oneshot: sunshine TEST xScripts.rxdata\nRuby version: #{RUBY_VERSION}\nSDL version: #{Sunshine::SDLVersion_major}.#{Sunshine::SDLVersion_minor}.#{Sunshine::SDLVersion_micro}")
end
