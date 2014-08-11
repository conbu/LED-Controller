==============
LED Controller
==============

if you wanna give the line 6 to Red is 10, Green is 20 and Blue is 30,
issue GET request as below.

```
curl http://server:9292/6/10/20/30
```

then you'll get response

```
LINE: 6
R: 10
G: 20
B: 30
```

as text/plain and LED's controlled by line 6 received RGB values.




