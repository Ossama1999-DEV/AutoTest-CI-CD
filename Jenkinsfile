pipeline {
    agent {
        docker {
            image 'gcc:latest'
        }
    }

    triggers {
        pollSCM('H/3 * * * *')
    }

    stages {
        stage('Build') {
            steps {
                sh 'cd tools && make'
            }
        }

        stage('Run') {
            steps {
                sh 'cd tools && ./app'
            }
        }

        stage('Archive') {
            steps {
                archiveArtifacts artifacts: 'tools/app', fingerprint: true
            }
        }
    }
}