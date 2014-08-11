require 'sinatra'


get '/:line/:r/:g/:b' do
  line = params[:line]
  r = params[:r]
  g = params[:g]
  b = params[:b]
  # ToDo: validate params
  body = []
  body << "LINE: #{line}"
  body << "R: #{r}"
  body << "G: #{g}"
  body << "B: #{b}"
  # ToDo: conroll LED
  response = Rack::Response.new do |r|
    r.status = 200
    r['Content-Type'] = 'text/plain'
    r.write(body.join "\n")
  end
  response.finish
end

