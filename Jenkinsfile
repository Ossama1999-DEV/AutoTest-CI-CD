pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'gcc main.c -o app'
            }
        }

        stage('Run') {
            steps {
                sh './app'
            }
        }
    }
}