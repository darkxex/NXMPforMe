NXMP for Me
======
NXMP for Me is a custom build of video player (NXMP) for Nintendo Switch with Special Addons.
- OverClocked (CPU, GPU and EMC) (thanks to the overclock, the shaders and the interpolation now work amazing)
- Select default subtitle language.
- Video interpolation (4 Modes)
![2022020500491500-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152627703-f11b9cfb-9cf9-456d-9da1-106f440ec40a.jpg)
![2022020500492300-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152627706-2d784cab-e574-4dc0-9113-309a3dff69f3.jpg)
![2022020417382700-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152600762-00fc3684-88b1-4511-b218-dbe49ba6147b.jpg)
![2022020417383400-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152600767-b7384517-0adb-486a-a12c-8962b062a7ec.jpg)
![2022020417390000-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152600781-24d11f1d-d3be-490a-a325-a17828c32844.jpg)
![2022020417391000-5A5FEC0B9A2FB2402F211552C541E27F](https://user-images.githubusercontent.com/17991404/152600789-1c81e063-d304-4357-8a1d-ff06f41871bd.jpg)

----------------------------------------------------------------------------

![Banner](docs/banner.jpg)
NXMP is a video player for Nintendo Switch based on [MPV](https://mpv.io/).
NXMP support most popular video format , it support HTTP,FTP,SFTP,Samba streaming and it also support Enigma2 decoders.

Installation 
----
Edit config.ini
```
[Main]
startpath=/switch/nxmp

[Network]

[Enigma2]
```

Network have syntax (you can add as many source as you like)

```
[Network]
source=TESTFtp|ftp://user:pass@192.168.1.10:21/path/
source=TestHTTP|http://192.168.1.10/path/
source=TestSFTp|sftp://192.168.1.10/path/ (without path it default to home)
source=TestSamba|smb://192.168.1.10/share/ (share is a share name not a path)
```

Enigma2 have syntax
```
[Enigma2]
e2address=http://192.168.1.10/
```

Copy "nxmp" folder to switch sdcard (/switch/nxmp)

Usage
-----
Buttons Mapping
- A select (play/pause during playback)
- B back (stop during playback)
- Y Main Menu
- X show OSD (during playback)
- R L ZR ZL (seek +/-  during playback)
- \+ Exit NXMP
- R Stick Button Toggle Masterlock (during playback, only A button will work)
- Dpad Right (during playback show/hide right menu)
- Dpad Down (during playback show/hide player UI)
- R Stick Up/Down Fast Scroll on file list (Volume Control During Playback)
- \- Show file selection during playback


FAQ
-----
**Question:** My 4K file dont work? Why?

**Answer** Keep in mind that currently Homebrew apps can't access the HW Decoder, so all is done with CPU, 4K file is too heavy to be decoded

**Q:** What is Enigma2?

**A:** Enigma2 is an application used in Linux-based Digital Video Broadcasting (DVB-S, DVB-C, DVB-T) receivers or TV set-top boxes and Internet Protocol television receivers.

**Q:** What is ShaderMania?

**A:** ShaderMania is an useless but fun feature of NXMP, it uses the ability of MPV to load custom shader into the video output chain. I adopt some shaders from https://www.shadertoy.com/ to make shaders effects to the video. Some like grayscale may be usefull for someone others (like the sea shaders) is only for fun. Users can also make their custom shaders and place in mpv/shaders directory.

Thanks to
-----
- proconsule (Original and Official NXMP). 
- Cpasjuste for pPlay https://github.com/Cpasjuste/pplay some code was taken here (mpv part)
- DarkMatterCore for libusbhsfs https://github.com/DarkMatterCore/libusbhsfs (this gives NXMP USB support)
- bodyXY @ GBATemp forum for banner and icons
- Godorowski @ GBATemp forum for player UI design and icons
- Chocola @ GBATemp forum for usage guide and beta testing
- student @ reboot.ms forum for beta testing
- docgold @ GBATemp forum for Enigma2 samples and support on decoders
- tataniko @ GBATemp forum for suggestions and bug hunting
- All guys on GBAtemp
