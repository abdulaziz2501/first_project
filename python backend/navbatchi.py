from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///lifts.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class Lift(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50), nullable=False)
    status = db.Column(db.String(20), nullable=False)

@app.before_first_request
def create_tables():
    db.create_all()

@app.route('/')
def index():
    lifts = Lift.query.all()
    return render_template('index.html', lifts=lifts)

@app.route('/update/<int:id>', methods=['GET', 'POST'])
def update(id):
    lift = Lift.query.get_or_404(id)
    if request.method == 'POST':
        lift.status = request.form['status']
        db.session.commit()
        return redirect(url_for('index'))
    return render_template('update.html', lift=lift)

if __name__ == '__main__':
    app.run(debug=True)
