# ESP32 LoRa UAV Telemetry

Bidirectional telemetry link between two ESP32 nodes over LoRa (433 MHz): a **simulated UAV (node A)** and a **ground station (node B)**.
This is Project 0 – the first stage of my 26-week UAV software roadmap.

## Status

Early stage – work in progress (October 2026).

- [x] Repository structure and PlatformIO project for node A
- [x] First firmware running on the ESP32 (serial output)
- [x] Engineering log for every work session (`docs/log`)
- [x] Boot banner: node name, firmware version, reset reason
- [x] Non-blocking timing with `millis()`
- [ ] SPI communication with the LoRa Ra-02 module
- [ ] Binary packet protocol with CRC
- [ ] Ground-station logger in Python (serial → CSV)
- [ ] Web dashboard for live telemetry (JavaScript)
- [ ] Automated tests (pytest)

## Architecture

```
[Node A – simulated UAV]  ── LoRa 433 MHz ──▶  [Node B – ground station]  ── USB serial ──▶  [PC: Python logger / web dashboard]
     ESP32 + Ra-02         ◀── commands ───          ESP32 + Ra-02
```

## Hardware

| Part | Qty | Notes |
|---|---|---|
| ESP32 DevKit (ESP-WROOM-32, 30-pin, CH9102) | 2 | one per node |
| LoRa Ra-02 (SX1278, 433 MHz) | 2 | SPI |

## Repository layout

| Folder | Contents |
|---|---|
| `firmware/` | PlatformIO projects: `node_a`, `node_b` |
| `protocol/` | packet format specification |
| `tools/` | PC-side scripts (Python) |
| `tests/` | test plans and automated tests |
| `data/`, `analysis/` | recorded telemetry and analysis |
| `docs/` | architecture notes and the engineering log |

## Build and upload

Requires VS Code with the PlatformIO extension.

```bash
cd firmware/node_a
pio run -t upload          # build and flash (hold BOOT if the upload cannot connect)
pio device monitor -b 115200
```

## Engineering log

Each session is documented in [`docs/log`](docs/log): goal, what was done, errors and fixes, lessons learned and open questions.

## Roadmap

1. **Telemetry link** – this repository
2. **PX4 SITL** – flight-controller simulation
3. **Autopilot + companion computer**

## Author

Bartłomiej Cieślak – [LinkedIn](https://www.linkedin.com/in/bartlomiej-cieslakuav)
