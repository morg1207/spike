## 1 LAUNCH_ROS
Libraries Overview


### 1.1 ACTIONS
In ROS2, the launch_ros.actions library provides tools to manage nodes, parameters, namespaces, and other configurations in launch files. Here are some of the key classes and functions available in launch_ros.actions:
Key Classes and Functions

    ComposableNodeContainer: Creates a container for composable nodes.
    LifecycleNode: Manages the lifecycle state of nodes.
    LoadComposableNodes: Loads composable nodes at runtime.
    Node: Launches a ROS node.
    PushRosNamespace: Sets a namespace for nodes.
    RosTimer: Triggers events after a specified duration.
    SetParameter: Sets a parameter for a node.
    SetParametersFromFile: Loads parameters from a file.
    SetRemap: Remaps topic names.
    SetUseSimTime: Sets whether to use simulated time.

### 1.1.1 Node Usage

The Node action is central in ROS2 launch files, as it defines the nodes to be launched with their respective parameters and configurations.

Syntax:

```python

Node(
    package='your_package_name',
    executable='your_executable',
    name='node_name',
    output='screen',  # Outputs to console or log
    parameters=[{'param_name': param_value}],
    ros_arguments=['--ros-args'],  # Optional ROS-specific arguments
    emulate_tty=True,
    arguments=['--arg1', '--arg2']  # Optional CLI arguments
)
```
Example:

```python


Node(
    package='my_robot_package',
    executable='my_robot_node',
    name='my_robot',
    output='screen',
    parameters=[{'use_sim_time': True}],
    ros_arguments=['--log-level', 'INFO']
)


```

## 2 LAUNCH
[**************************************************]: # 
### 2.1 ACTIONS

#### 2.1.1 DeclareLaunchArgument

```python
DeclareLaunchArgument(
    name='argument_name',
    default_value='default_value',
    description='Description of the argument'
    choices=['sim_robot', 'real_robot'],
)

```
#### 2.1.2 IncludeLaunchDescription

```python
launch_ekf = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(path_launch_ekf
))
```
[**************************************************]: # 
### 2.2 launch_description_sources

#### 2.2.1 PythonLaunchDescriptionSource

```python
    def __init__(
        self,
        launch_file_path: SomeSubstitutionsType,
    ) -> None:

```
[**************************************************]: # 
### 2.3 launch_description_sources

#### 2.3.1 PythonLaunchDescriptionSource

```python
    def __init__(
        self,
        launch_file_path: SomeSubstitutionsType,
    ) -> None:

```
[**************************************************]: # 
### 2.4 substitutions

#### 2.4.1 PathJoinSubstitution

```python
    def __init__(
        self,
        launch_file_path: SomeSubstitutionsType,
    ) -> None:

```