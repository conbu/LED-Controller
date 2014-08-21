require 'sinatra'
require 'serialport'

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
  send(line.to_i, r.to_i, g.to_i, b.to_i)
  response = Rack::Response.new do |r|
    r.status = 200
    r['Content-Type'] = 'text/plain'
    r.write(body.join "\n")
  end
  response.finish
end

def send(l, r, g, b)
  # sp = SerialPort.new('/dev/tty.usb-serialdevice', 9600, 8, 1, 0)
  sp = SerialPort.new('/dev/tty.usbmodem621', 9600, 8, 1, 0)
  [l, r, g, b].each do |data|
    sp.write(data.chr)
  end
  sp.close
end

