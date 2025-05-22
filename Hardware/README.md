# STM32C071_Basic Hardware

## Adapting the design to suit your project

Pin functions on the MCU are configured for minimum layout complexity
for UART, I2C and SPI, but KiCad knows what alternate functions are
possible. If you need different pin functions, you should reconfigure
them.

You may obviously change the size of the PCB by redrawing the Edge Cuts
rectangle.

## Libraries

This Kicad project has a local [project](project.kicad_sym) library and
uses [jlcbasic](https://github.com/cjheath/jlcbasic) and
[jlcpreferred](https://github.com/cjheath/jlcpreferred) libraries from
Github.  These libraries are expected to be checked-out somewhere
together, and this directory should contain a symbolic link to their
parent directory.  If you can't use a symbolic link, make the
(libraries)[libraries] directory and check out those projects inside
that.

## Hardware choices

So far as possible, parts are chosen to be easy for a relative novice to
hand-solder.  Accordingly, the smallest parts are 0805 packages, and the
MCU is a QFP, not a leadless version.  The cheapest possible parts have
been chosen throughout, with a preference for JLCPCB parts that have no
extra assembly changes.

# Power supply

The 3.2V power supply should be capable of more than 700mA, which is all
the power that 5V USB guarantees.  If you intend to use this much power,
you should increase the size of the tantalum capacitor on the output.

The power supply is designed to sink heat to the grond plane on the back
of the board. You might wish to remove the ground plane elsewhere, but
consider leaving it in this area if you need low noise or heatsinking.
