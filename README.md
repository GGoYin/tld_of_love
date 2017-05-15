This is an adaptation of arthurv's [OpenTLD](https://github.com/arthurv/OpenTLD).<br>
The test.avi is downloaded from [here](http://vision.ucsd.edu/~bbabenko/project_miltrack.shtml).<br>

Reason
==
I have modified the tracking box from rectangle to heart shape for the festival activity of [Make "Love" by Myself](http://www.guokr.com/post/588130/) on guokr.com ^.^

How to use?
==
* Open cmd;<br>
* find the TLDLove.exe;<br>
* type:<br>
```shell
TLDLove.exe -s [path of video] -p [path of parameter config file]
```
  you should mark the target by you mouse at the first frame.<br>
  you can use custom camera by ignoring the -s parameter:
```shell
TLDLove.exe -p [path of parameter config file]
```
Notice
==
`Do not forget the parameter file(parameters.yml)!`
