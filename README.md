# MetalTone.lv2
Overdrive/Distortion

![MetalTone](https://github.com/brummer10/MetalTone/blob/main/MetalTone.png?raw=true)


## Features

- Distortion Pedal simulation. 

MetalTone is modeled after the renowned BOSS MT-2 Metal Zone(*), a high gain distortion pedal with an advanced EQ section.

It has standard active EQ controls with a massive 15dB of cut/boost range for the lows and highs.
It also sports a parametric active EQ for the mids with two controls: the frequency, and the boost/cut amount.

The midfreq parameter has a very wide range, going from 200Hz all the way to 5kHz. As a result, it's better to think of it simply as a single highly flexible active EQ, 
and disregard the idea that it's only for shaping the mids.

(*) 'Other product names modeled in this software are trademarks of their respective companies that do not endorse and are not associated or affiliated with this software.
BOSS MT-2 Metal Zone is a trademark or trade name of another manufacturer and was used merely to identify the product whose sound was reviewed in the creation of this 
product. All other trademarks are the property of their respective holders.'

## Dependencys

- libcairo2-dev
- libx11-dev

## Binary

[![build](https://github.com/brummer10/MetalTone/actions/workflows/build.yml/badge.svg)](https://github.com/brummer10/MetalTone/actions/workflows/build.yml)

[MetalTone.lv2.zip](https://github.com/brummer10/MetalTone/releases/download/Latest/MetalTone.lv2.zip)

## Build

- git submodule init
- git submodule update
- make
- make install # will install into ~/.lv2 ... AND/OR....
- sudo make install # will install into /usr/lib/lv2
