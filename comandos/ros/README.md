### COMANDOS ROS

```bash
ros2 topic pub -r 10 /greetings example_interfaces/msg/String "{data: 'Hello from terminal'}"

ros2 service call /server_init_localization rb1_interfaces/srv/InitLocalization "{station_position: {x: 0.4, y: 0.0, z: 2.0}}"
```
