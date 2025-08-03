# XR Tracking Sim — Embedded Linux (QEMU)

**Goal:** Real-time ArUco marker pose estimation pipeline that runs on an emulated ARM Linux (QEMU) to simulate XR tracking on embedded hardware.

---

## Features

- Real-time webcam capture using OpenCV
- Marker detection & pose estimation (OpenCV ArUco)
- Visual pose overlay
- Cross-compiled for ARM with QEMU emulation
- Ready for performance profiling (FPS, CPU usage)

---

## Build Instructions (Host)

```bash
./scripts/build.sh
