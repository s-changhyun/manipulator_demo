/**
 * @file /include/robotis_manipulator_h_gui/main_window.hpp
 *
 * @brief Qt based gui for robotis_manipulator_h_gui.
 *
 * @date November 2010
 **/
#ifndef robotis_manipulator_gui_MAIN_WINDOW_H
#define robotis_manipulator_gui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace robotis_manipulator_gui {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void closeEvent(QCloseEvent *event); // Overloaded function

    /******************************************
    ** Transformation
    *******************************************/
    Eigen::MatrixXd rotationX( double angle );
    Eigen::MatrixXd rotationY( double angle );
    Eigen::MatrixXd rotationZ( double angle );

    Eigen::MatrixXd rotation2rpy( Eigen::MatrixXd rotation );
    Eigen::MatrixXd rpy2rotation( double roll, double pitch, double yaw );

    Eigen::Quaterniond rpy2quaternion( double roll, double pitch, double yaw );
    Eigen::Quaterniond rotation2quaternion( Eigen::MatrixXd rotation );

    Eigen::MatrixXd quaternion2rpy( Eigen::Quaterniond quaternion );
    Eigen::MatrixXd quaternion2rotation( Eigen::Quaterniond quaternion );

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
    void on_actionAbout_triggered();

    void on_curr_joint_button_clicked( bool check );
    void on_des_joint_button_clicked( bool check );

    void on_curr_pos_button_clicked( bool check );
    void on_des_pos_button_clicked( bool check );
//    void on_exe_button_clicked( bool check );

    void on_ini_pose_button_clicked( bool check );
    void on_set_mode_button_clicked( bool check );

    void on_demo_start_button_clicked( bool check );
    void on_demo_stop_button_clicked( bool check );

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

    void update_curr_joint_pose_spinbox( manipulator_demo_module_msgs::JointPose msg );
    void update_curr_kinematics_pose_spinbox( manipulator_demo_module_msgs::KinematicsPose msg );

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

    std::vector<std::string> joint_name;

    QList<QAbstractSpinBox *> joint_spinbox;
};

}  // namespace robotis_manipulator_gui

#endif // robotis_manipulator_gui_MAIN_WINDOW_H
