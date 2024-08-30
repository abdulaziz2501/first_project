from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('update/<int:pk>/', views.update_status, name='update_status'),
]
